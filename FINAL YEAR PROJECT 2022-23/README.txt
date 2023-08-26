Project Title : Blood Vessel Extraction from Retinal Images
								
Prepared by : 1. Ayan Ghosh (Roll No. 33)
	      2. Moitrish Maity (Roll No. 48)
	      3. Aviree Mukhopadhyay (Roll No. 49)
	      4. Ankita Nandi (Roll No. 51)

This project consist of five different algorithms and one proposed algorithm for extracting blood vessels from retinal images. Those algorithms (code and input & output images(.pgm)) are listed in six different folders named 'BOTTOM HAT TRANSFORMATION','CENTRELINE METHOD','FILTERS AND MORPHOLOGICAL OPERATIONS','ILLUMINATION NORMALIZATION','MORPHOLOGICAL BIT PLANE' and 'PROPOSED METHOD' respectively.

1.BOTTOM HAT TRANSFORMATION////////////////////

In this method, first green channel is extracted from the grayscale image. After that for removing salt and pepper noise Median(Median.c) , Adaptive Median(Adaptive Median.c) and Decision Based Unsymmetric Trimmed Median Filter(DBUTM.c) is applied. Then Gaussian Filter(GAUSS.c) is applied in order to remove gaussian noise, if present. Bottom Hat Transform(Bottom_hat.c) is applied to extract the blood vessels which is a morphological operation used to extract bright features from the darker background. Finally, by applying the unsharp masking technique(unsharp.cpp) on the resultant image, the edges of the blood vessels are more enhanced. 

2. CENTERLINE METHOD//////////////////

This methodology involves a series of image processing techniques, including using a large kernel mean filter(Image Average Filter.c) and background normalization(Background Normalisation.c) to enhance vessels. Morphological operations, such as the top hat transformation(combination of Dilation operation.c and Erosion operation.c) , are then utilized to highlight vessel structures. Finally, a vessel filling technique(Region growing.c) is applied to make the blood vessels more prominent and removes any gap or broken link between the thinner blood vessels. 

3. FILTERS AND MORPHOLOGICAL OPERATIONS//////////////////////////

In this method, first step is Pre-processing that consist of complement green channel, Contrast Limited Adaptive Histogram Equalization (CLAHE.c) and morphological opening (Erosion followed by a dilation)(combination of Dilation.c and Erosion.c). After that, the last step is segmentation. In this research, the segmentation method that used are median filters(Median filter.c) and gaussian filter(Gaussian.c).

4. ILLUMINATION NORMALIZATION METHOD////////////////////////////////

In this method, initially the green channel is extracted from the retinal vessel, which is considered for further processing. Then CLAHE (Contrast limited adaptive histogram equalization)(CLAHE.c) is applied on the green channel to enhance the contrast of each section. Then the illumination normalization is done by using the Homomorphic High Pass filter (High pass filter.c). After that opening operation(combination of Dilation operation.c and Erosion operation.c) and thresholding operation(Thresholding.c) is applied to obtain the blood vessels.

5. MORPHOLOGICAL BIT PLANE//////////////////////////////////////

A single binary image is obtained by taking the sum of the top two-bit planes(bitplane.c) which are bit plane 6 and bit plane 7. This partial reconstruction(bitsrecons.c) along with the detected vessel centrelines is used in vessel filling. On the other hand, background normalization(Background Normalisation.c) is then applied to equalize intensity levels and improve vessel visibility to a grayscale version of a fundus image.

6. PROPOSED METHOD///////////////////////////////////

In this paper, we propose an algorithm for the effective and accurate extraction of blood vessels from retinal images. First step is the implementation of Homomorphic High Pass filter(High pass filter.c). Then Sobel operator(Sobel operator.c) has been used for edge detection, especially to identify the retinal boundary line. To obtain the retinal area, region growing technique(Region growing.c) has been used in our approach.Then morphological operations such as erosion and dilation have been used in the closing operation(combination of Dilation operation.c and Erosion operation.c) in order to get prominent blood vessels.



All the output images are marked as '01_test_final_op.pgm' , '16_test_final_op.pgm' and '19_test_final_op.pgm'.


