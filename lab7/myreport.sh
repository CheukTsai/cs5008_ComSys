#!/bin/bash

# Sys Report Generation

TITLE="System Information Report"
CURRENT_TIME=$(date)

report_uptime(){
# echo "uptime report generated"
cat<<EOF
System Uptime:
  $(uptime)
EOF
return
}

report_disk_space(){
# disk space report generated
cat<<EOF
Disk Space
$(df)
EOF
return
}

report_home_space(){
#home space report generated
cat<<EOF
Home space
$(du)
EOF
return
}

cat<<EOF
#TITLE for $HOSTNAME
## $TITLE
The report is generated by $USER at $CURRENT_TIME
Data here
$(report_uptime)
$(report_disk_space)
$(report_home_space)
EOF