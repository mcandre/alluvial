ARTIFACT=obj_dir/Valluvial

all: test

$(ARTIFACT): Makefile main.cpp rtl/alluvial/alluvial.sv rtl/alluvial/fulladder_chain.sv rtl/alluvial/fulladder.sv
	@verilator \
		-Wall \
		-Wno-UNOPTFLat \
		--cc \
		--exe \
		main.cpp \
		rtl/alluvial/alluvial.sv
	@make \
		-j \
		-C obj_dir \
		-f Valluvial.mk \
		Valluvial

test: $(ARTIFACT)
	@$(ARTIFACT)

clean:
	-rm -rf obj_dir
