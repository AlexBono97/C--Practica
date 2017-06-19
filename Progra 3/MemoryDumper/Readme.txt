This is the example program accompanying the blog post "Reading RAM/memory from
another process":
http://blog.mh-nexus.de/2013/12/reading-rammemory-from-another-process/



When you run MemoryDumper, you will see a console window with something similar
to this:



	MSBuild.exe  (PID: 13872)
	<unknown>  (PID: 6184)
	MSBuild.exe  (PID: 6984)
	<unknown>  (PID: 12420)
	MemoryDumper.exe  (PID: 13548)
	<unknown>  (PID: 13340)

	Test data address for current process (PID: 13548): 0x0131483C

	Choose one of the above PIDs: <user entry>
	Read 16 bytes starting at address: <user entry>

	0131483C  73 6F 6D 65 74 65 73 74 07 41 20 42 20 43 09 0A  sometest.A B C..

	Press any key to exit...



The beginning is a list of all the processes whose memory can be read. Each line
contains the executable name (or "<unknown>" if it could not be retrieved) and
the process ID (PID).

For convenience in testing process memory reading, a known working test data
address and its owning process are given (see "Test data address[...]" above).
The test data is the string "sometest\7A B C\t\n" and is defined in
MemoryDumper.cpp. The PID of the process containg the test data (current running
instance of MemoryDumper.exe) is given as well as the address of this string.

You will be promted for a PID and for an address. The PID can be chosen from the
process list. Picking working addresses is more difficult. You have to know what
address really contains data (memory is allocated and readable). Addresses that
are often readable are 0x10000 or 0x400000.
If you cannot find any working PID and address try the ones from the test data.

Hint: There is a shortcut for user data entry to simplify debugging. Entering 0
for PID will select the current running instance of MemoryDumper.exe. Entering 0
for address will select the address of the test data string.

The output is simply a line with the address (hexadecimal) where reading
started, then comes the representation of the 16 bytes as pairs of hexadecimal
digits, and finally the representation of the same bytes as ASCII encoded
string.

Technically this is not really ASCII, but whatever code page / encoding is the
default on your system for console applications. In the most cases this will be
some super set of ASCII. Non-printable characters are replaced by a dot (.).
