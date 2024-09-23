FROM debian:12

RUN apt-get update && apt-get install -y gnupg2 curl

RUN curl -fsSL https://nginx.org/keys/nginx_signing.key | apt-key add -

RUN echo "deb http://nginx.org/packages/debian/ bookworm nginx" \
    | tee /etc/apt/sources.list.d/nginx.list

RUN apt update && apt install -y nginx

WORKDIR /var/www/html

RUN chown -R www-data:www-data /var/www/ \
&& chmod -R 755 /var/www/

COPY ./conf /etc/nginx/conf.d/default.conf

EXPOSE 80

CMD [ "nginx", "-g", "daemon off;" ]
