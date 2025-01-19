srcs := $(wildcard src/*.c src/*/*.c)
objs := $(srcs:%.c=%.o)
deps := $(srcs:%.c=%.d)

CPPFLAGS := -std=c99 -MMD -MP -Iinclude $(xcppflags)
CFLAGS := $(xcflags)
LDFLAGS := $(xldflags)
LDLIBS := $(xldlibs)

libcx.a: libcx.a($(objs))

clean:
	rm -f libcx.a src/*.o src/*/*.o src/*.d src/*/*.d

-include $(deps)
