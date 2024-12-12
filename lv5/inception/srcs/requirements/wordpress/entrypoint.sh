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

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

useradd -m env_setter
sudo -u env_setter -i -- \
wp config create \
    --path=/var/www/html \
    --dbname=${MYSQL_DATABASE} \
    --dbuser=${MYSQL_USER} \
    --dbhost=mariadb \
    --dbpass=${MYSQL_PASSWORD}

exec "$@"
