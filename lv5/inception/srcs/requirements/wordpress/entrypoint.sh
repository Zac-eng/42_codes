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

#runnning wordpress with the user www-data
chown -R www-data:www-data /var/www/html/ && \
chmod -R 755 /var/www/html/

#installing wp command
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

#setting database_name, user_name, user_password
useradd -m env_setter

sudo -u env_setter -i -- \
wp config create \
    --path=/var/www/html \
    --dbname=${MYSQL_DATABASE} \
    --dbuser=${MYSQL_USER} \
    --dbhost=mariadb \
    --dbpass=${MYSQL_PASS}

sudo -u env_setter -i -- \
wp core install \
    --path=/var/www/html \
    --url="https://${DOMAIN_NAME}" \
    --title="${WP_TITLE}" \
    --admin_user="${WP_ADMIN}" \
    --admin_password="${WP_ADMIN_PASS}" \
    --admin_email="${WP_ADMIN_EMAIL}"

sudo -u env_setter -i -- \
wp user create ${WP_USER} ${WP_USER_EMAIL} \
    --path=/var/www/html \
    --user_pass=${WP_USER_PASS}

mkdir -p /run/php

exec "$@"
