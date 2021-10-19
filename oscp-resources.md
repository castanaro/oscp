# OSCP (and day-to-day hacking) Resources:

### Target Enum

* scan-Pn() and vuln() bash functions (see helpful-aliases file within this repo to view these functions)
* Autorecon

### Web Enum

* Fuzz Faster U Fool (FFUF): a tool written in Go for directory enumeration (use with common.txt, directory lists medium and big)
* Nikto
* Davtest

### Priv Esc

* Tiberius' Udemy Priv Esc Courses
* Linux Smart Enum: https://github.com/diego-treitos/linux-smart-enumeration
* LinPEAS: https://github.com/carlospolop/PEASS-ng/tree/master/linPEAS
* WinPEAS: https://github.com/carlospolop/PEASS-ng/tree/master/winPEAS
* Linux: https://blog.g0tmi1k.com/2011/08/basic-linux-privilege-escalation/
* Windows: https://www.fuzzysecurity.com/tutorials/16.html

### General Tools/References

* HackTricks: https://book.hacktricks.xyz/
* Sushant's Total OSCP Guide: https://sushant747.gitbooks.io/total-oscp-guide/content/
* IppSec (The Master): https://ippsec.rocks/?#
* Reverse Shell Generation: https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md
* Web Shell: https://github.com/WhiteWinterWolf/wwwolf-php-webshell
* Hydra
* Burp
* Hashcat
* Wireshark

### Hacking Platforms

* Proving Grounds (Offsec's HTB Platform)
* Virtual Hacking Labs
* Hack the Box
* OSCP Labs
* Try Hack Me (BoF Room)

### Personal OSCP Approach

1. Run scan-Pn (see target enum section above)
1. Run autorecon (AS SUDO)
Run legion/sparta scan (Optional)
Run nmap -sU --top-ports 30 (and 100) to confirm UDP (or look at top 20 from autorecon)
Run vuln (see bashrc for alias)
Run nmap nse scripts against the port if all else fails
Review autorecon results - look at udp specifically
Recursively enumerate any interesting web directories
Searchsploit all discovered services - don't be afraid to try exploits for versions > discovered version
Try default creds everywhere… try bruteforcing ftp even if anon:anon found (Hydra is helpful, but as a last resort ESPECIALLY with Postgres, manually type these in)
		a. Admin:admin
		b. Guest:guest
		c. Administrator:administrator
		d. Anonymous:anonymous
		e. Root:root (linux)
		f. TRY THE [NAME OF SERVICE]:[NAME OF SERVICE] - Think back on BillyBoss - creds were nexus:nexus
ALWAYS LOOK FOR HIDDEN FILES IN EVERY DIRECTORY
If you find an smbshare, last resort, try to navigate to a url with that name as a directory e.g., http://[IP]/sharename (wouldn't hurt to also throw any unique names such as the name of the box into the common.txt wordlist so it searches on it as well…)
Don't forget about sql injection :)
Look at source code for creds


#### more to come...
