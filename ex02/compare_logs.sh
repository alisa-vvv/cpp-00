#!/usr/bin/env bash

print_only_field2 () {
	awk '{print $2}' $1;
}
diff -y <(print_only_field2 "./my.log") <(print_only_field2 "./19920104_091532.log") > diff
