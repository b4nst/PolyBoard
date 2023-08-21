#ifndef PAGE_H
#define PAGE_H

#define PAGE_COUNT 8

typedef struct Page {
  int scale_type;
  unsigned char key;
  unsigned char octave;
} __attribute__((aligned(8))) Page;

typedef struct PageManager {
  Page pages[PAGE_COUNT];
  unsigned char current_page;
} __attribute__((aligned(128))) PageManager;

/**
 * @brief      Initialize the page manager.
 * @param      pages  The pages
 * @param[in]  page   The current index of the page
 */
void page_manager_set(Page pages[PAGE_COUNT], unsigned char page);
/**
 * @brief      Change the current page.
 * @param[in]  page  The page index
 * @return     The page
 */
const Page *change_page(unsigned char page);
/**
 * @brief      Get the given page.
 * @param[in]  page  The page index
 * @return     The page
 */
const Page *get_page(unsigned char page);
/**
 * @brief      Get the current page index.
 * @return     The current page index
 */
unsigned char get_current_page();
/**
 * @brief      Change the current page scale type.
 * @param[in]  scale_type  The scale type
 */
void change_page_scale_type(int scale_type);
/**
 * @brief      Change the current page key.
 * @param[in]  key   The key
 */
void change_page_key(unsigned char key);
/**
 * @brief      Change the current page octave.
 * @param[in]  octave  The octave
 */
void change_page_octave(unsigned char octave);

#endif // PAGE_H
