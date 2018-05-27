//
// Created by 少聪  梁 on 2018/5/26.
//

#ifndef THOR_THORASSERT_H
#define THOR_THORASSERT_H
#include <stdio.h>
#include <stdlib.h>
namespace thor{
#define THOR_ASSERT(X) \
  do { \
    if((X) == false) {   \
     fprintf(stderr, "Thor asserttion '%s' failed in %s " \
                     "at %s:%d\n", \
                      #X, __PRETTY_FUNCTION__, __FILE__, __LINE__);  \
      abort();  \
    } \
  } while(false)
}
#endif //THOR_THORASSERT_H
