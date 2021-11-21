
tars/gmp-6.2.0.tar.xz: | tars/
	wget https://ftp.gnu.org/gnu/gmp/gmp-6.2.0.tar.xz -O tars/gmp-6.2.0.tar.xz
	touch $@

gmp/extracted: tars/gmp-6.2.0.tar.xz | gmp/
	tar -axvf $< -C $| --strip-components=1
	touch $@

gmp/configured: gmp/extracted | gmp/
	cd $|; ./configure --prefix="${PWD}"
	touch $@

gmp/made: gmp/configured
	make -C gmp/ -j `nproc`
	touch $@

gmp/installed.mk: gmp/made
	make -C gmp/ install
	touch $@

