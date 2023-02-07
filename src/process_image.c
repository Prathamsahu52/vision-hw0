#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in'
    float pixel=im.data[x+y*im.w+c*im.w*im.h];
    return pixel;

}

void set_pixel(image im, int x, int y, int c, float v)
{

    im.data[x+y*im.w+c*im.w*im.h]=v;
    // TODO Fill this in
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);

    for(int i=0;i<im.w*im.h*im.c;i++){
        copy.data[i]=im.data[i];
    }

    // TODO Fill this in
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);

    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            float r=get_pixel(im,i,j,0);
            float g=get_pixel(im,i,j,1);
            float b=get_pixel(im,i,j,2);
            float gray_pixel=0.299*r+0.587*g+0.114*b;
            set_pixel(gray,i,j,0,gray_pixel);
        }
        
    }


    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            float pixel=get_pixel(im,i,j,c);
            set_pixel(im,i,j,c,pixel+v);
        }
    }
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in

    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            for(int k=0;k<im.c;k++){
                float pixel=get_pixel(im,i,j,k);
                if(pixel>1){
                    set_pixel(im,i,j,k,1);
                }
                if(pixel<0){
                    set_pixel(im,i,j,k,0);
                }
            }
        }
    }


}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
    
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            
            float r=get_pixel(im,i,j,0);
            float g=get_pixel(im,i,j,1);
            float b=get_pixel(im,i,j,2);

            float cmax=three_way_max(r,g,b);
            float cmin=three_way_min(r,g,b);

            float V=cmax;
            float S=0;

            if(V==0){
                S=0;
            }
            else{
                S=(cmax-cmin)/V;
            }
            
            float H=0;

            if(cmax==r){
                H=((g-b)/(cmax-cmin));
            }
            else if(cmax==g){
                H=2+(b-r)/(cmax-cmin);
            }
            else if(cmax==b){
                H=4+(r-g)/(cmax-cmin);
            }

            H=H*60;

        }
    }
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
