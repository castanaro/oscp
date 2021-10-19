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

1. Run scan-Pn function (see target enum section above)
2. Run vuln (see bashrc for alias)
3. Run autorecon (AS SUDO)
4. Run legion as backup (optional)
5. Run nmap -sU --top-ports 30 (and 100) to confirm UDP (or look at autorecon udp results)
6. Recursively enumerate any interesting web directories and run nikto (where applicable)
7. Searchsploit and Google all discovered services (don't be afraid to try unverified exploits)
8. Try default creds wherever possible
   1. admin:admin 
   2. guest:guest
   3. administrator:administrator
   4. anonymous:anonymous
   5. root:root
   6. name-of-box:name-of-box
   7. name-of-service:name-of-service
9. See if there are hidden files
10. Navigate to SMB shares in the browser as a last resort (e.g., http://[IP]/sharename)
11. Don't forget about SQL Injection
12. Look at source code for creds

#### more to come...
