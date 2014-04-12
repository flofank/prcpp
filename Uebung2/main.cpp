#include <iostream>
#include "C:\work\workspaces\prcpp\Matrix.h"

JNIEXPORT void JNICALL Java_Matrix_multiplyC (JNIEnv* env, jobject, jdoubleArray mA, jdoubleArray mB, jdoubleArray mR, jint bCols, jint aRows, jint aCols) {
	double* mAP = env->GetDoubleArrayElements(mA, 0);
	double* mBP = env->GetDoubleArrayElements(mB, 0);
	double* mRP = env->GetDoubleArrayElements(mR, 0);
	for (int c = 0; c < bCols; c++) {
		// Für jede Spalte in m
		for (int r = 0; r < aRows; r++) {
			// Für jede Zeile in this
			double val = 0;
			for (int e = 0; e < aCols; e++) {
				// Für jedes Element in dieser Zeile von this
				val += mAP[r * aCols + e] * mBP[e * bCols + c];
			}
			mRP[r * bCols + c] = val;
		}
	}
	env->ReleaseDoubleArrayElements(mA, mAP, 0);
	env->ReleaseDoubleArrayElements(mB, mBP, 0);
	env->ReleaseDoubleArrayElements(mR, mRP, 0);
}

JNIEXPORT void JNICALL Java_Matrix_powerC (JNIEnv * env, jobject, jdoubleArray mA, jdoubleArray mB, jdoubleArray mR, jint size, jint k) {
	double* mAP = env->GetDoubleArrayElements(mA, 0);
	double* mBP = env->GetDoubleArrayElements(mB, 0);
	double* mRP = env->GetDoubleArrayElements(mR, 0);
	while(--k > 0) {
		for (int c = 0; c < size; c++) {
			for (int r = 0; r < size; r++) {
				double val = 0;
				for (int e = 0; e < size; e++) {
					val += mAP[r * size + e] * mBP[e * size + c];
				}
				mRP[r * size + c] = val;
			}
		}
		double* buff = mAP; 
		mAP = mRP;
		mRP = buff;
	}
	if (k % 2==1) { // Matrix A enthält Resultat
		for (int c = 0; c < size; c++) {
			for (int r = 0; r < size; r++) {
				mRP[r * size + c] = mAP[r * size + c];
			}
		}
		env->ReleaseDoubleArrayElements(mA, mAP, 0);
		env->ReleaseDoubleArrayElements(mB, mBP, 0);
		env->ReleaseDoubleArrayElements(mR, mRP, 0);
	} else {
		env->ReleaseDoubleArrayElements(mR, mAP, 0);
		env->ReleaseDoubleArrayElements(mB, mBP, 0);
		env->ReleaseDoubleArrayElements(mA, mRP, 0);
	}
}