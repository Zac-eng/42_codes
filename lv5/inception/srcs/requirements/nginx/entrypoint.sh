#!/bin/bash
#entrypoint.sh

set -e

sed -i "s/DOMAIN_NAME/$DOMAIN_NAME/g" /etc/nginx/conf.d/default.conf
sed -i "s/CERTS_LOCATION/$CERTS_LOCATION/g" /etc/nginx/conf.d/default.conf

exec "$@"
