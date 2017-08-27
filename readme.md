### Disk recovery experiments 

Print MBR:
```
 g++ mbr.cpp -o mbr && sudo ./mbr
```

Search for sector containing Master File Table (NTFS)
 ```
 g++ search_mft.cpp -o search_mft && sudo ./search_mft
```