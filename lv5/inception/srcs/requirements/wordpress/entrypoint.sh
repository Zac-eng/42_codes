#!/bin/bash
# entrypoint.sh

mkdir -p /var/www/html
cd /var/www/html

wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz &&\
    mv ./wordpress/* /var/www/html && \
    rm -rf latest.tar.gz wordpress && \
    apt clean && rm -rf /var/lib/apt/lists/*

chown -R www-data:www-data /var/www/html/ && \
    chmod -R 755 /var/www/html/

echo "define( 'DB_NAME', 'wordpress_db' );" >> /var/www/html/wp-config.php
echo "define( 'DB_USER', 'hmiyazak' );" >> /var/www/html/wp-config.php
echo "define( 'DB_PASSWORD', 'harutoM1yazak1' );" >> /var/www/html/wp-config.php
echo "define( 'DB_HOST', 'mariadb' );" >> /var/www/html/wp-config.php

exec "$@"
