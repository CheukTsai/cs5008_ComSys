#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Assert007.h"

void AssertionFailure(const char *exp, const char *file,
                      const char *baseFile, int line) {
  if (!strcmp(file, baseFile)) {
    fprintf(stderr,
            "Assert007(%s) failed in file %s, line %d\n", exp, file, line);
  } else {
    fprintf(stderr,
            "Assert007(%s) failed in file %s (included from %s), line %d\n",
            exp, file, baseFile, line);
  }
  exit(EXIT_FAILURE);
}
