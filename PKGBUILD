# $Id: PKGBUILD 60970 2011-12-19 21:33:58Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>
# Packager: Ian D Brunton <iandbrunton@gmail.com>

pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
groups=(customised)
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
gitcommit="1658e962859c"
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	http://hg.punctweb.ro/dwm/raw/$gitcommit/01-dwm-6.0-pertag2.diff
	http://hg.punctweb.ro/dwm/raw/$gitcommit/02-dwm-6.0-push.diff
	http://hg.punctweb.ro/dwm/raw/$gitcommit/08-dwm-6.0-clicktofocus.diff
	http://hg.punctweb.ro/dwm/raw/$gitcommit/15-dwm-6.0-centred-floating.diff
	http://hg.punctweb.ro/dwm/raw/$gitcommit/17-dwm-6.0-statuscolors.diff
	http://dwm.suckless.org/patches/dwm-5.7.2-attachaside.diff
	centredfloating.diff
	gaps.diff
	config.h
	dwm.desktop)

build() {
  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h
  patch -Np1 -i $srcdir/dwm-5.7.2-attachaside.diff
  patch -Np1 -i $srcdir/01-dwm-6.0-pertag2.diff
  patch -Np1 -i $srcdir/02-dwm-6.0-push.diff
  patch -Np1 -i $srcdir/08-dwm-6.0-clicktofocus.diff
  patch -Np1 -i $srcdir/centredfloating.diff
  patch -Np1 -i $srcdir/15-dwm-6.0-centred-floating.diff
  patch -Np1 -i $srcdir/17-dwm-6.0-statuscolors.diff
  patch -Np1 -i $srcdir/gaps.diff
  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}

md5sums=('8bb00d4142259beb11e13473b81c0857'
         '89f923f55c8884477218df89f197df0c'
         'a6cccebdeb8c1eeebb7835fd9d29cbd3'
         'cc28d5116625acb05a4e9176acc0fac7'
         '150242a35710dba41a70dff0fa15a3f0'
         '770d2b3469456888f2a83fad68656cc2'
         'a92ee04c33b1082da61b55d3617249eb'
         'b4b1959c129826d63443873f1be7814e'
         '5c787611f4a3d999b5874dad0b665e97'
         'cdf308224e46de391ad4ab32536402ce'
         '939f403a71b6e85261d09fc3412269ee')
