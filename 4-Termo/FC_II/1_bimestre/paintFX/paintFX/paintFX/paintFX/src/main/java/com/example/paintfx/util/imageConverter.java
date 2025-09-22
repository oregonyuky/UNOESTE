package com.example.paintfx.util;

import javafx.embed.swing.SwingFXUtils;
import javafx.scene.image.Image;
import javafx.scene.image.WritableImage;

import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import javafx.scene.image.PixelReader;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class imageConverter {
    public static Image toGrayScale(Image image){
        int[] pixel = {0, 0, 0, 0};
        BufferedImage bufferedImage;
        bufferedImage = SwingFXUtils.fromFXImage(image, null);
        WritableRaster writableRaster = bufferedImage.getRaster();
        int media;
        for(int y=0;y<image.getHeight();y++){
            for(int x=0;x<image.getWidth();x++){
                writableRaster.getPixel(x, y, pixel);
                media = (int)(pixel[0]*0.2126 +  pixel[1]*0.7152 +  pixel[2]*0.0722);
                pixel[0] = pixel[1] = pixel[2] = media;
                writableRaster.setPixel(x, y,pixel);
            }
        }
        image = SwingFXUtils.toFXImage(bufferedImage, null);
        return image;
    }
    public static Image toEspelhoHorizontal(Image image) {
        BufferedImage bufferedImage = SwingFXUtils.fromFXImage(image, null);
        WritableRaster raster = bufferedImage.getRaster();
        int width = (int)image.getWidth();
        int height = (int)image.getHeight();
        int[] pixel = new int[4];
        for(int y=0;y<height;y++){
            for(int x=0;x<width/2;x++){
                int mirrorX = width - 1 - x;
                raster.getPixel(x, y, pixel);
                int[] pixelMirror = new int[4];
                raster.getPixel(mirrorX, y, pixelMirror);
                raster.setPixel(x, y, pixelMirror);
                raster.setPixel(mirrorX, y, pixel);
            }
        }
        return SwingFXUtils.toFXImage(bufferedImage, null);
    }
    public static Image toEspelhoVertical(Image image){
        BufferedImage bufferedImage = SwingFXUtils.fromFXImage(image, null);
        WritableRaster raster = bufferedImage.getRaster();
        int width = (int)image.getWidth();
        int height = (int)image.getHeight();
        int[] pixel = new int[4];
        for(int i=0;i<width;i++){
            for(int j=0;j<height/2;j++){
                int mirrorY = height - j - 1;
                int[] newpixel = new int[4];
                raster.getPixel(i, j, pixel);
                raster.getPixel(i, mirrorY, newpixel);
                raster.setPixel(i, j, newpixel);
                raster.setPixel(i, mirrorY, pixel);
            }
        }
        return SwingFXUtils.toFXImage(bufferedImage, null);
    }
    public static Image toPretoBranco(Image image){
        BufferedImage bufferedImage = SwingFXUtils.fromFXImage(image, null);
        WritableRaster raster = bufferedImage.getRaster();
        int[] pixel = new int[4];
        int w = (int)image.getWidth();
        int h = (int)image.getHeight();
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                raster.getPixel(i, j, pixel);
                int gray = (int)(pixel[0]*0.2126 + pixel[1]*0.7152 + pixel[2]*0.0722);
                if(gray<128)gray=0;
                else gray=255;
                pixel[0] = pixel[1] = pixel[2] = gray;
                raster.setPixel(i, j, pixel);
            }
        }
        return SwingFXUtils.toFXImage(bufferedImage, null);
    }
    public static Image toInverterCores(Image image) {
        if (image == null) return null;

        int width = (int) image.getWidth();
        int height = (int) image.getHeight();

        WritableImage output = new WritableImage(width, height);
        PixelReader reader = image.getPixelReader();
        PixelWriter writer = output.getPixelWriter();

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Color cor = reader.getColor(x, y);

                // inverte cada componente RGB
                Color invertida = new Color(
                        1.0 - cor.getRed(),   // R
                        1.0 - cor.getGreen(), // G
                        1.0 - cor.getBlue(),  // B
                        cor.getOpacity()      // mantém a transparência
                );

                writer.setColor(x, y, invertida);
            }
        }

        return output;
    }
}
