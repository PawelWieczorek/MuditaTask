clean:
	rm -rf ./output
	cd Program1 && $(MAKE) clean
	cd Program2 && $(MAKE) clean


all: clean
	mkdir -p output
	cd Program1 && $(MAKE) all RELEASE=1
	cp -f Program1/output/release/Program1exec ./output
	cd Program2 && $(MAKE) all RELEASE=1
	cp -f Program2/output/release/Program2exec ./output