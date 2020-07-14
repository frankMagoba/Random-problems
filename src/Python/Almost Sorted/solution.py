def setup():
    array_size = int(input())
    string_array = input()
    int_array = []

    for each_int in string_array.split(' '):
        int_array.append(int(each_int))

    return int_array

def is_ascending(int_array):
    prev_int = int_array[0]
    is_ascending = True
    for each_int in int_array:
        if each_int >= prev_int:
            prev_int = each_int
        else:
            is_ascending = False
            break
    return is_ascending

def is_valid_swap(int_array, j1, j2):
    int_array[j1], int_array[j2] = int_array[j2], int_array[j1]
    return is_ascending(int_array)
    
#This func assumes int_array is not already sorted
#assumes length >= 3
def sort_array(int_array):
    length = len(int_array)
    j1 = None #index one
    j2 = None #index two
    count = 0 #counts how many numbers are in incorrect order
    prev_int = int_array[0] #previous integer to compare
    i = 0 #iterating index

    while i < length:
        curr_int = int_array[i]

        if curr_int >= prev_int:
            prev_int = curr_int

        else:
            if j1: #ie if j1 is not None
                j2 = i
            else:
                j1 = i-1
                j2 = i
            count+=1
            prev_int = curr_int
        i+=1
        
    if j1 and j2: #ie if j1 is not None and j2 is not None
        if count == 2: #aka two numbers need to be swapped that arent next to each other
            print("yes")
            print("swap", j1 + 1, j2 + 1)
            return

        elif count == 1: #aka two numbers next to each other need to be swapped or input isnt possible
            if is_valid_swap(int_array, j1, j2):
                print("yes")
                print("swap", j1 + 1, j2 + 1)
            else:
                print("no")
        else: #aka a portion needs to be reversed or not possible
            if count != j2 - j1:
                print("no")
            else:
                print("yes")
                print("reverse", j1 + 1, j2 + 1)
    else:
        print("no")
    
def main():
    int_array = setup()
    if len(int_array) == 1 or is_ascending(int_array):
        print("yes")
        return
        
    #for now on it can be assumed the array isn't sorted
    elif len(int_array) == 2:
        print("yes")
        print("swap 1 2")
        return
    
    else:
        sort_array(int_array)

if __name__ == "__main__":
    main()