
print-license:
	split -l 40 LICENSE page-
	echo "Page (1/3)" > head1.txt
	echo "" >> head1.txt
	echo "Page (2/3)" > head2.txt
	echo "" >> head2.txt
	echo "Page (3/3)" > head3.txt
	echo "" >> head3.txt
	echo "                                                                 ../.." > foot.txt
	cat head1.txt page-aa foot.txt > page1.txt
	cat head2.txt page-ab foot.txt > page2.txt
	cat head3.txt page-ac > page3.txt
	rm -f page-a? head*.txt foot.txt
