/* C_inputlib version 8.5
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "inputlib.h"

/* an implementation of the POSIX getline() function. read below
 * for differences in specs.
 *
 * Inputs
 * 1) *lineptr must point to an area allocated using the malloc()
 *    family of functions, or it must be NULL. if *lineptr is NULL,
 *    then the function starts by allocating its own memory and storing
 *    the address in *lineptr. Otherwise, the area pointed to by
 *    *lineptr is used by the function, growing it using realloc()
 *    as required.
 * 2) *n is the size of the area associated with *lineptr. The initial
 *    value inside *n doesn't matter if *lineptr is set to NULL.
 * 3) stream should be an input stream or an update stream or a NULL
 *    pointer. if it is a NULL pointer, the input is automatically taken
 *    from stdin. Otherwise, stream is the stream from which input is to
 *    be taken.
 *
 * Return value
 * zero
 *  in this case *lineptr and *n are left unmodified.
 *  this occurs if
 *   1) lineptr was NULL
 *   2) n was NULL
 *   3) EOF or read error occurred before the function was able to scan
 *      anything useful.
 *   4) *lineptr was NULL and the function failed to initially allocate
 *      an one byte storage for the empty string.
 * nonzero
 *   the return value is the number of bytes among the *n bytes that were
 *   stored into by this function.
 *
 * Notes
 * *lineptr must be freed using free() to avoid memory leaks.
 *
 * special notes when *lineptr is not NULL
 * 1) the function will use the storage area pointed to by *lineptr.
 *    Since the function grows the area using realloc(), the value of
 *    *lineptr might change, causing the previous value to become invalid.
 *    an attempt to access the storage pointed to by the previous *lineptr
 *    is undefined behaviour. in case a copy of the previous pointer was
 *    made, it must be updated after a call to this function.
 * 2) providing an incorrect size in *n is undefined behaviour
 *
 * this implementation is cross platform, but it is certainly slower than
 * a built-in library function. If you have such a function available, then
 * you should avoid using this.
 *
 * further, this function does not follow the specs of POSIX. In particular,
 * it does not set errno to anything, and it does not use an ssize_t type
 * as its return value. the function consumes all input till the first newline
 * character that appears. This is true even if there isn't enough space to
 * store all the characters. The newline character is discarded and not stored
 * in the storage area pointed to by *lineptr.
 *
 * the strings formed by this function are always null terminated. However,
 * the standard library functions may fail to operate properly if the input
 * itself somehow contained a null character.
 * A test for this case can be written as
 * strlen(*lineptr) == one less than the return value of this function,
 * given it was nonzero.
 */
size_t cust_getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL)
        return 0;
    if (stream == NULL)
        stream = stdin;

    /* do this instead of (feof(stream) || ferror(stream))
     * because it is possible that eof or error indicator has
     * not yet been set, but the next read attempt would set it
     */
    int ch = getc(stream);
    if (ch == EOF)
        return 0;

    if (*lineptr == NULL) {
        *lineptr = malloc(1);
        if (*lineptr)
            *n = 1;
        else {
            ungetc(ch, stream);
            return 0;
        }
    }

    size_t i = 0;
    while (ch != '\n' && ch != EOF) {
        if (i == *n - 1) {
            if (*n <= SIZE_MAX / 2) {
                char *temp = realloc(*lineptr, *n * 2);
                if (temp != NULL) {
                    *n *= 2;
                    *lineptr = temp;
                } else
                    break;
            } else
                break;
        }
        (*lineptr)[i++] = ch;
        ch = getc(stream);
    }
    (*lineptr)[i++] = '\0';

    /* if ch is not the newline character, consume input until
     * newline occurs
     */
    while (ch != '\n' && ch != EOF)
        ch = getc(stream);

    return i;
}
