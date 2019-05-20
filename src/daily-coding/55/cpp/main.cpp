#include <cctype>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_map>

std::string random_string(std::size_t size) {
  const std::string alphabet =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";
  std::random_device rd;
  static std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dist(0, alphabet.size());

  std::stringstream ss;
  for (std::size_t i = 0; i < size; ++i) {
    std::size_t idx = dist(gen);
    ss << alphabet[idx];
  }
  return ss.str(); 
}

class UrlShortener {

public:
  UrlShortener(std::size_t len) : len_(len) {}

  std::string shorten(const std::string& url) {
    if (shortened_lookup_.find(url) != shortened_lookup_.end()) {
      return shortened_lookup_[url];
    }
    // Create small URL
    auto short_url = random_string(len_);
    while (address_lookup_.find(short_url) != address_lookup_.end()) {
      short_url = random_string(len_);
    }
    // Store mapping
    address_lookup_[short_url] = url;
    shortened_lookup_[url] = short_url;
    
    // Return small URL
    return short_url;
  }

  /**
   * Fetches the shortened URL, returning the empty string
   * if no such URL exists.
   */
  std::string restore(const std::string& short_url) {
    // Fetch small URL
    if (address_lookup_.find(short_url) == address_lookup_.end()) return "";
    return address_lookup_[short_url];
  }
private:
  std::size_t len_;
  std::unordered_map<std::string, std::string> address_lookup_;
  std::unordered_map<std::string, std::string> shortened_lookup_;
}; // class UrlShortener


int main() {
  auto shortener = UrlShortener(6);
  std::string url = "https://test.url.com";
  std::string short_url = shortener.shorten(url);
  std::cout << "Shortened " << url << " to " << short_url << '\n';

  return 0;
}
