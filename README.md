qplugininfo
===========

Print a few very basic informations of a Qt plugin.

### Setup

	git clone https://github.com/panzi/qplugininfo.git
	mkdir qplugininfo/build
	cd qplugininfo/build
	cmake .. -DCMAKE_INSTALL_PREFIX=/usr
	make
	sudo make install

### Usage

	qplugininfo /path/to/libsomething.so

### Example

	$ qplugininfo /usr/lib64/qt4/plugins/imageformats/libqvtf.so
	plugin: /usr/lib64/qt4/plugins/imageformats/libqvtf.so
	address: 0x24200d0
	object name: 
	class name: ValveTextureFilePlugin
	class info:
	        author: Mathias Panzenböck
	        url: https://github.com/panzi/qvtf
	class name: QImageIOPlugin
	class name: QObject

### License

Copyright (c) 2014 Mathias Panzenböck

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
