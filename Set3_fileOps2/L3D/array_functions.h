#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

/**
 * @brief Allocates an integer array of a target size on the free store.
 * Upon function return, pArray will point to starting address.
 * 
 * @param pArray pointer to integer array
 * @param INIT_SIZE initial array size as an integer
 * 
 * @note Runtime of function O(?)
 */
void array_allocate(int* &pArray, int);

/**
 * @brief Returns the value of the element at a target position.  If the
 * position it not within the array size, returns zero.
 * 
 * @param pARRAY pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to retrieve value from
 * @return int element value at given position (or zero if out of range)
 * 
 * @note Runtime of function O(?)
 */
int array_get_element_at(int *pArray, int, int);

/**
 * @brief Sets the value of the element at a target position.  If the
 * position is out of range, does nothing.
 * 
 * @param pARRAY pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to set value at
 * @param VALUE value to place at target position
 * 
 * @note Runtime of function O(?)
 */
void array_set_element_at(int *pArray, int, int, int);

/**
 * @brief Deallocates an integer array, returning its memory back to
 * the free store.  Upon function return, pArray will be set to be a
 * null pointer and the array size will be set to zero.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * 
 * @note Runtime of function O(?)
 */
void array_deallocate(int* &pArray, int&);

/**
 * @brief Inserts a value at a target position.  If the position is
 * out of range, inserts at the front/back as appropriate.  Upon
 * function return, the array will be increased in size by one.  The
 * array size will be updated to the new size.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to insert value at
 * @param VALUE value to insert at target position
 * 
 * @note Runtime of function O(?)
 */
void array_insert_at_position(int* &pArray, int&, const int, const int);

/**
 * @brief Returns the minimum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 * 
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int minimum value within the array
 * 
 * @note Runtime of function O(?)
 */
int array_min(int *pArray, const int);

/**
 * @brief Returns the maximum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 * 
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int maximum value within the array
 * 
 * @note Runtime of function O(?)
 */
int array_max(int *pArray, const int);

/**
 * @brief Returns the first position within an array a target value 
 * is located at.  If the target value is not present within the 
 * array, returns -1.
 * 
 * @param pARRAY pointer to the integer array (the haystack)
 * @param SIZE size of the array as an integer
 * @param TARGET target integer value to search for in the array (the needle)
 * @return int position within the array target value is located (or -1 if not present)
 * 
 * @note Runtime of function O(?)
 */
int array_find(int *pArray, const int, const int);

/**
 * @brief Removes a value at a target position.  If the position is
 * out of range, removes from the front/back as appropriate.  Upon
 * function return, the array will be decreased in size by one.  The
 * array size will be updated to the new size.
 * 
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to remove value from
 * 
 * @note Runtime of function O(?)
 */
void array_remove_from_position(int* &pArray, int&, const int);

#endif