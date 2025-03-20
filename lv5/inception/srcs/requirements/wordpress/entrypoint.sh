#!/bin/bash
# entrypoint.sh

mkdir -p /var/www/html
cd /var/www/html

#fetching wordpress files
wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz &&\
    mv ./wordpress/* /var/www/html && \
    rm -rf latest.tar.gz wordpress && \
    apt clean && rm -rf /var/lib/apt/lists/*

#installing wp command
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

#setting database_name, user_name, user_password
useradd -m wp-installer

chown -R wp-installer:wp-installer /var/www/html/
chmod -R 755 /var/www/html/

sudo -u wp-installer -i -- \
wp config create \
    --path=/var/www/html \
    --dbname=${MYSQL_DATABASE} \
    --dbuser=${MYSQL_USER} \
    --dbhost=mariadb \
    --dbpass=$(cat /run/secret/mysql_pass)

sudo -u wp-installer -i -- \
wp core install \
    --path=/var/www/html \
    --url="https://${DOMAIN_NAME}" \
    --title="${WP_TITLE}" \
    --admin_user="${WP_ADMIN}" \
    --admin_password="${WP_ADMIN_PASS}" \
    --admin_email="${WP_ADMIN_EMAIL}"

sudo -u wp-installer -i -- \
wp user create ${WP_USER} ${WP_USER_EMAIL} \
    --path=/var/www/html \
    --user_pass=${WP_USER_PASS}

#runnning wordpress with the user www-data
chown -R www-data:www-data /var/www/html/ && \

mkdir -p /run/php

exec "$@"
