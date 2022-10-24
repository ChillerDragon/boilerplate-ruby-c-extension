#include "ruby.h"
#include "extconf.h"

// your custom ruby function written in C
VALUE rb_print_str(VALUE _self, VALUE str) {
	Check_Type(str, T_STRING);
	puts(StringValueCStr(str));
	return Qnil;
}

// your simple custom ruby function written in C
VALUE rb_return_nil() {
	return Qnil;
}

// this function name has to match
// Init_<filename>
void Init_lib_print_str() {
	VALUE mod = rb_define_module("PrintStrModule");

	//            module  ruby name     C name         number of arguments
	rb_define_method(mod, "print_str",  rb_print_str,  1);
	rb_define_method(mod, "do_nothing", rb_return_nil, 0);
}

