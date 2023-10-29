#include <stdio.h>
#include "graf.h"


void CreateGraph(Teman *g)
{
    JumlahTeman(*g) = 0;
    int i,j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            HubunganTeman(*g, i, j) = 0;
        }
    }
}

void addName(Teman *graph, Word friendName)
{
    if (JumlahTeman(*graph) < 20)
    {
        NamaTeman(*graph, JumlahTeman(*graph)) = friendName;
        JumlahTeman(*graph)++;
    }
    else
    {
        printf("Sudah tidak bisa lagi menambah.\n");
    }
}

void addFriendship(Teman *graph, Word friend1, Word friend2)
{
    int index1 = -1, index2 = -1;
    int i;
    // Check apakah nama sudah terdaftar
    for (i = 0; i < JumlahTeman(*graph); i++)
    {
        if (isEqualWord(NamaTeman(*graph, i), friend1))
            index1 = i;
        if (isEqualWord(NamaTeman(*graph, i), friend2))
            index2 = i;
    }
    if (index1 != -1 && index2 != -1)
    {
        // Jika mereka belum berteman
        if (HubunganTeman(*graph, index1, index2) == 0 && HubunganTeman(*graph, index2, index1) == 0)
        {
            HubunganTeman(*graph, index1, index2) = 1;
            HubunganTeman(*graph, index2, index1) = 1;
        }
        //Jika mereka sudah berteman
        else
        {
            printf("Mereka sudah berteman.\n");
        }
    }
    //Tidak ada salah satu nama dalam daftar
    else
    {
        printf("Salah satu nama tidak terdaftar.\n");
    }
}

void addFriend(Teman *graph, Word friendName) {
    if (JumlahTeman(*graph) < 20) {
        NamaTeman(*graph, JumlahTeman(*graph)) = friendName;
        JumlahTeman(*graph)++;
    }
}

void showFriends(Teman *graph, Word friendName) {
    int index = -1;
    int j,i;
    for (i = 0; i < JumlahTeman(*graph); i++) {
        if (isEqualWord(NamaTeman(*graph, i), friendName))
            index = i;
    }
    if (index != -1) {
        printf("%s's friends:\n", friendName);
        for (j = 0; j < JumlahTeman(*graph); j++) {
            if (HubunganTeman(*graph, index, j) == 1)
                printf("%s\n", NamaTeman(*graph, j));
        }
    } else {
        printf("Salah satu nama tidak terdaftar.\n");
    }
}

void removeFriendship(Teman *graph, Word friend1, Word friend2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < JumlahTeman(*graph); i++) {
        if (isEqualWord(NamaTeman(*graph, i), friend1))
            index1 = i;
        if (isEqualWord(NamaTeman(*graph, i), friend2))
            index2 = i;
    }
    if (index1 != -1 && index2 != -1) {
        if (HubunganTeman(*graph, index1, index2) == 1 && HubunganTeman(*graph, index2, index1) == 1) {
            HubunganTeman(*graph, index1, index2) = 0;
            HubunganTeman(*graph, index2, index1) = 0;
        } else {
            printf("Mereka memang bukan teman.\n");
        }
    } else {
        printf("Salah satu nama tidak terdaftar.\n");
    }
}

int countFriends(Teman *graph, Word friendName) {
    int index = -1;
    for (int i = 0; i < JumlahTeman(*graph); i++) {
        if (isEqualWord(NamaTeman(*graph, i), friendName))
            index = i;
    }
    if (index != -1) {
        int count = 0;
        for (int j = 0; j < JumlahTeman(*graph); j++) {
            if (HubunganTeman(*graph, index, j) == 1)
                count++;
        }
        return count;
    } else {
        return -1; // Jika tidak ada namanya dalam daftar
    }
}


