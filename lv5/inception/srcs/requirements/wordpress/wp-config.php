<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the website, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** Database username */
define( 'DB_USER', 'hmiyazak' );

/** Database password */
define( 'DB_PASSWORD', 'harutoM1yazak1' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'ZE+4l,oP{G%4K{6F61sM:iJyBlc}U|wDQiBL0(GA^}@D_ZL|J>@)=|l6~JF9<)`4' );
define( 'SECURE_AUTH_KEY',  'luaVdx;Z[CiDC=GQe0uQj%<!ido!#$t v$Iw&&XD3! 1HU6oFY5//2-#<-3S%:nL' );
define( 'LOGGED_IN_KEY',    'Q+j/#?f1KA~VS}!3uP-^BTti|`(pxd:qsYS 2q7BUU+X~:MIJ.-E[xizGCv5/V>O' );
define( 'NONCE_KEY',        'QKC#Lf?iohn%bW_%bn{4NJ3Vv1=kC7-Vl^&C7$w>s>Bq2{xnGv=%7Je4Z!MV8]a2' );
define( 'AUTH_SALT',        'RHG,<4#P4gSi/b]9lD^1L8mSMn.a;=S$_2i#:M+H/Z0dLYHqD}oi8=*%&0g.W$XL' );
define( 'SECURE_AUTH_SALT', 'y$uRmD#0[7`)jc^s].yB]nK_!1H<m#ZbpM.jkb(}hEz)V|jQwkIPG5KXi1v%XdJx' );
define( 'LOGGED_IN_SALT',   'g|oviat29p06q7`qC{EZ)G&kl%-lCAaJz@Zxh<`@IP#,<`%o<P3eY`ZwW~{ fk1B' );
define( 'NONCE_SALT',       '=^WX6=YCps$RhHz%?P*qy3ApX]G$Ga[u3yiJ=q<>H_/;C2VsXV}FE<61s0.+nOZf' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 *
 * At the installation time, database tables are created with the specified prefix.
 * Changing this value after WordPress is installed will make your site think
 * it has not been installed.
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/#table-prefix
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://developer.wordpress.org/advanced-administration/debug/debug-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
