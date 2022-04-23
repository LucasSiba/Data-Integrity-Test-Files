CFLAGS   = -O2 -g -rdynamic -fPIC -fstack-protector -fno-strict-aliasing -fno-omit-frame-pointer \
		   -Wall -Werror -Wextra -Wcast-align -Wcast-qual -Wformat=2 -Wformat-security \
		   -Wmissing-prototypes -Wnested-externs -Wredundant-decls -Wshadow \
		   -Wstrict-prototypes -Wno-unknown-pragmas -Wunused -Wno-unused-result \
		   -Wwrite-strings -Wno-attributes -Wduplicated-cond -Wlogical-op -Wnull-dereference \
		   -Wjump-misses-init -Wdouble-promotion

all: a
