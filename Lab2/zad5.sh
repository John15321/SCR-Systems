#!/bin/bash
trap "echo Trapped SIGINT signal" INT

trap "echo Trapped SIGQUIT signal" SIGQUIT

trap "echo Trapped SIGFPE signal" SIGFPE

trap "echo Trapped SIGILL signal" SIGILL





echo "pid is $$"
while (( COUNT < 10  ))
do
    sleep 10
    (( COUNT ++ ))
    echo "$COUNT"
done
exit 0
