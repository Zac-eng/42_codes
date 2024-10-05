CREATE DATABASE wordpress_db DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER 'boss'@'192.168.65.1' IDENTIFIED BY 'b0ss_passW0rd';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'192.168.65.1';
CREATE USER 'hmiyazak'@'192.168.65.1' IDENTIFIED BY 'harutoM1yazak1';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hmiyazak'@'192.168.65.1';
CREATE USER 'boss'@'127.0.0.1' IDENTIFIED BY 'b0ss_passW0rd';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'127.0.0.1';
CREATE USER 'hmiyazak'@'127.0.0.1' IDENTIFIED BY 'harutoM1yazak1';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hmiyazak'@'127.0.0.1';
FLUSH PRIVILEGES;
