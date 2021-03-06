#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

const char *RIFF_TAGS[] = {
    "RIFF",
    "MDLH",
    "MDLG",
    "MDLN",
    "SMAP",
    "PARA",
    "CRAS",
    "BBOX",
    "RADI",
    "MDLD",
    "TEXT",
    "MATE",
    "INDE",
    "VERB",
    "VERT",
    "TANS",
    "BMAP",
    "SKIN",
    "TRAN",
    "AMAP",
    "SCEN",
    "SGAL",
    "SGVL",
    "SGJC",
    "SGBR",
    "LODT",
    "LODE",
    "PART",
    "ANIB",
    "XANH",
    "XANL",
    "XANI",
    "XANS",
    "XANK",
    "PLAL",
    "PLAT",
    "REFL",
    "REFP",
    "ATTO",
    "SHAM", nullptr};

struct guid
{
    u_int32_t id_0;
    u_int16_t id_1;
    u_int16_t id_2;
    u_int16_t id_3;
    u_int8_t id_4[16];
} __attribute__((packed));

struct XANI
{
    unsigned _unkwon_0;
    guid id;
    float length;
    

} __attribute__((packed));

int main(int argc, char const *argv[]) {

    u_int8_t *buffer = new u_int8_t[0x800000];
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return fd;

    size_t len = read(fd, buffer, 0x800000);
    close(fd);
    if (len < 0)
        return len;

    printf("len = %lu\n", len);

    for (int i = 0; RIFF_TAGS[i] != nullptr; i++) {

        unsigned count = 0;
        for (int j = 0; j < len; j++) {
            if (strncmp(RIFF_TAGS[i], (const char *)&buffer[j], 4) == 0) {
                count++;
            }
        }
        printf("%s count = %u\n", RIFF_TAGS[i], count);
    }

    delete buffer;
    return 0;
}
