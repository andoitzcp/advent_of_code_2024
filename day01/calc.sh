paste <(awk '{print $1}' input | sort) <(awk '{print $2}' input | sort) | awk '{sum += sqrt(($1 - $2)^2)} END {print sum}'
