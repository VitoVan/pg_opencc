PG_CFLAGS := $(shell pkg-config  --cflags opencc)
PG_CPPFLAGS := $(shell pkg-config  --cflags opencc)
PG_CXXFLAGS := $(shell pkg-config  --cflags opencc)
PG_LDFLAGS := $(shell pkg-config  --libs opencc)
PG_LIBS := $(shell pkg-config  --libs opencc)
MODULES = pg_opencc
EXTENSION = pg_opencc
DATA = pg_opencc--0.2.sql
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
