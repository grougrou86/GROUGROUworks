Alias /@MYWEBAPP@ "@PATH_WEBAPP@/@MYWEBAPP@/" 
<Directory "@PATH_WEBAPP@/@MYWEBAPP@/">
    Options Indexes FollowSymLinks MultiViews
    AllowOverride all
        Order Deny,Allow
	Deny from all
	Allow from 127.0.0.1
</Directory>
