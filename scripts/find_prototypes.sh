awk 'prev ~ /^[A-Za-z].*\)$/ && /^\{/ {print prev ";"} {prev=$0}' ../*.c
