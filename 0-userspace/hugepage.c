#include <stdio.h>
#include <stdlib.h> // malloc
#include <sys/mman.h>
#include <asm/mman.h>
#include <sys/types.h>
#include <unistd.h> // sleep

int main(int argc, char *argv[]) {
  size_t SIZE_2M = 1 << 30;
  char *addr = (char *)mmap(0, SIZE_2M, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_HUGETLB, -1, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }
  for (int i = 0; i < SIZE_2M; ++i) {
    addr[i] = 'a';
  }
  return 0;
}
