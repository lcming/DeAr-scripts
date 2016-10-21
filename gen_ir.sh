#!/bin/bash
dot_dir="./dot"
pdf_dir="./pdf"
full_file=$1;
file_name="${full_file%.*}";
dot_file="$dot_dir/$file_name.dot";
pdf_file="$pdf_dir/$file_name.pdf";
echo "test: $dot_file"
clang -S -emit-llvm -target mips-none-none "$1" -o tmp.txt; 
opt -O3 -instcombine -unroll-threshold=999999 tmp.txt -S -o tmp1.txt; 
sed 's/nocapture readonly //g' tmp1.txt > tmp2.txt;
graph-llvm-ir tmp2.txt;
echo "digraph G {" > $dot_file;
echo "compound=true" >> $dot_file;
grep -v "red\|\"_\|^\"arrayidx\|^\"i\|^\"output" tmp.dot | grep "^\"sum\|^\"sub\|^\"add\|^\"mul\|^\"sh\|^\"t" >> $dot_file;
echo "}" >> $dot_file;
./report.sh $dot_file;
dot $dot_file -Tpdf -o $pdf_file;
rm tmp*;
./parser.pl $dot_file






