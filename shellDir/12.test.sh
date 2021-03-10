#!/bin/bash
times=$1
declare -a data
for i in `seq 1 ${times}`; do
    if [[ ${i} -ne 1 ]];then
        echo -0n " "
    fi
    echo -n "$i"
    data[${i}]=0
done
echo ""

total=$[2**${times}]

function update_line(){
    local x 
    local carry=1
    for(( x=1; x<=${times}; x++ ));do
        sum=$[${data[$x]}+${carry}]
        if [[ ${sum} -eq 2 ]];then
            carry=1
            data[${x}]=0
        elif [[ ${sum} -eq 1 ]];then
            carry=0
            data[$x]=0
        fi
    done

}

    function print_line(){
        local x
        for ((x=${times}; x>=1; x--));do
            if [[ ${x} -ne ${times} ]];then
                echo -n " "
            fi
            echo -n ${data[${x}]}
        done
        echo ""
    }

print_line
for (( i=2; i<=${total};i++ ));do
    update_line
    print_line
done







