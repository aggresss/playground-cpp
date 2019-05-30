
#define malloc(x) malloc(x);\
fprintf(stderr, "%s malloc:%d\n", __FUNCTION__, x);\
fflush(stderr)

#define realloc(x,y) realloc((x),(y));\
fprintf(stderr, "%s realloc:%d\n", __FUNCTION__, y);\
fflush(stderr)

