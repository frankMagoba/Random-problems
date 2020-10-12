#include <stdio.h>
#include <stdint.h>

// Returns *index* of smallest of three numbers
uint32_t min3(uint32_t *args)
{
  uint32_t smallestidx = (args[0] <= args[1]) ? 0 : 1;
  smallestidx = (args[smallestidx] <= args[2]) ? smallestidx : 2;
  return(smallestidx);
}

uint32_t min7(uint32_t *args)
{
  uint32_t smallestidx = (args[min3(args)] <= args[min3(args + 3) + 3]) ? min3(args) : 3 + min3(args + 3);
  smallestidx = (args[smallestidx] <= args[6]) ? smallestidx : 6;
  return(smallestidx);
}

uint32_t test[7] = { 52, 78, 33, 21, 32, 60, 85};
char *days[7] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };

int main()
{
  printf("Index of smallest: %d\n", min7(test));
  printf("Smallest temperature: %d\n", test[min7(test)]);
  printf("Day with lowest temperature: %s\n", days[min7(test)]);
  
  return(0);
}