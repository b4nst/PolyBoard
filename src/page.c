#include "page.h"

static PageManager *get_page_manager_instance() {
  static PageManager manager_instance = {0}; // Singleton instance
  return &manager_instance;
}

void page_manager_set(Page pages[PAGE_COUNT], const unsigned char page) {
  PageManager *manager = get_page_manager_instance();
  for (unsigned char i = 0; i < PAGE_COUNT; ++i) {
    manager->pages[i] = pages[i];
  }
  manager->current_page = page;
}

const Page *change_page(const unsigned char page) {
  PageManager *manager = get_page_manager_instance();
  if (page < PAGE_COUNT) {
    manager->current_page = page;
  }
  return &manager->pages[manager->current_page];
}

const Page *get_page(const unsigned char page) {
  PageManager *manager = get_page_manager_instance();
  return &manager->pages[page];
}

unsigned char get_current_page() {
  PageManager *manager = get_page_manager_instance();
  return manager->current_page;
}

void change_page_scale_type(const int scale_type) {
  PageManager *manager = get_page_manager_instance();
  manager->pages[manager->current_page].scale_type = scale_type;
}

void change_page_key(const unsigned char key) {
  PageManager *manager = get_page_manager_instance();
  manager->pages[manager->current_page].key = key;
}

void change_page_octave(const unsigned char octave) {
  if (octave <= 10) {
    PageManager *manager = get_page_manager_instance();
    manager->pages[manager->current_page].octave = octave;
  }
}
