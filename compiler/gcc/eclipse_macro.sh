gcc -dM -E - < /dev/null \
    | sed 's%^#define %<macro><name>%' \
    | sed 's%[ ]%</name><value>%' \
    | sed 's%$%</value></macro>%' \
    | sed 's%^%            %' \
    > eclipse_xml_format.txt
