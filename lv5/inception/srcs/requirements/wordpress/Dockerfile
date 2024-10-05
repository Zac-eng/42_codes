FROM debian:12

ENV PHP_VERSION=8.2

RUN apt update && apt install -y \
  php${PHP_VERSION}-fpm \
  php${PHP_VERSION}-cli \
  php${PHP_VERSION}-mysql \
  php${PHP_VERSION}-curl \
  php${PHP_VERSION}-xml \
  php${PHP_VERSION}-mbstring \
  php${PHP_VERSION}-zip \
  php${PHP_VERSION}-intl\
  mariadb-client 

COPY php.ini /usr/local/etc/php/
COPY ./conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

WORKDIR /var/www/html

# install the wordpress files from remote
RUN apt update && apt install -y wget unzip && \
    wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz &&\
    mv ./wordpress/* /var/www/html && \
    rm -rf latest.tar.gz wordpress && \
    apt clean && rm -rf /var/lib/apt/lists/*

RUN chown -R www-data:www-data /var/www/html/ && \
    chmod -R 755 /var/www/html/

EXPOSE 9000

CMD [ "php-fpm8.2", "-F" ]
