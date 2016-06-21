#!/bin/bash

## Validation runs comparing 

## Run mcnp5
#/home/software/mcnp6.1.1/bin/./mcnp611_linux_x86_64_omp i=concrete.i n=concrete_results_new_ tasks 12

## Run facemc using root geometry
.././facemc --sim_info=concrete_hist.xml --geom_def=concrete_geom_root.xml --mat_def=concrete_mat.xml --resp_def=concrete_response.xml --est_def=concrete_est_root.xml --src_def=concrete_src.xml --cross_sec_dir=/home/software/mcnpdata --threads=12

## Run facemc using Cubit geometry
.././facemc --sim_info=concrete_hist.xml --geom_def=concrete_geom_cub.xml --mat_def=concrete_mat.xml --resp_def=concrete_response.xml --est_def=concrete_est.xml --src_def=concrete_src.xml --cross_sec_dir=/home/software/mcnpdata --threads=12
