BUILDDIR=$(abspath build)
SOURCEDIR=$(abspath src)
CSOURCES=$(wildcard $(SOURCEDIR)/*.c)
CPPSOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(CPPSOURCES)) $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(CSOURCES))


.PHONY: $(BUILDDIR)


all:	$(BUILDDIR) libadc.a


libadc.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $(BUILDDIR)/$@ $(OBJECTS)


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) $(CXXFLAGS) $< -o $@


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@


$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

clean:
	@rm -fr $(BUILDDIR)

