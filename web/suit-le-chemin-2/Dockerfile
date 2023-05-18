FROM alpine:latest

ENV TIMEZONE Europe/Paris

RUN apk add --no-cache curl php apache2 apache2-utils \
    php-apache2 \
    php-session \
    php-mysqli \
    composer \
    shadow

RUN mkdir /challenge && \
    chown apache:apache /challenge && \
    sed -i "s#^DocumentRoot \".*#DocumentRoot \"/challenge\"#g" /etc/apache2/httpd.conf && \
    sed -i "s#/var/www/localhost/htdocs#/challenge#" /etc/apache2/httpd.conf && \
    printf "\n<Directory \"/challenge\">\n\tAllowOverride All\nOptions -Indexes\n</Directory>\n" >> /etc/apache2/httpd.conf && \
    printf "ErrorLog /dev/stderr\nTransferLog /dev/stdout\n" >> /etc/apache2/httpd.conf

RUN usermod -d /home/apache/nouveau-dossier-perso apache
WORKDIR /challenge/
COPY app /challenge

COPY drapeau.txt /home/apache/nouveau-dossier-perso/3d0e88213ad0fee9f4dfcfa03c249728c2f96f1ee3c6bae393e097d95617d805/drapeau.txt

EXPOSE 80
CMD ["httpd", "-D", "FOREGROUND"]
