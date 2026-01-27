print_only_field2 () {
	awk '{print $2}' $1 > $1".diff";
}
print_only_field2 "./my.log"
print_only_field2 "./19920104_091532.log"
diff -y ./my.log.diff ./19920104_091532.log.diff > diff
rm ./my.log.diff ./19920104_091532.log.diff
