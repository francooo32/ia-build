#! bin/bash

if [[ -z $MNIST_ML_ROOT]]; then 
	echo "You must define a $MNIST_ML_ROOT"
	exit 1
fi

dir=${echo "$@" | tr a-z A-Z}
modele_name_lower=${echo "$@" | tr A-Z a-z}

mkdir -p $MNIST_ML_ROOT/$dir/include $MNIST_ML_ROOT/$dir/src
