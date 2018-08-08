#include <benchmark/benchmark.h>


#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <boost/container/flat_map.hpp>



static const std::map<std::string, int> map{
#include "elements.h"
};


static const std::unordered_map<std::string, int> unorderedMap{
#include "elements.h"
};


static const boost::container::flat_map<std::string, int> flatMap{
#include "elements.h"
};

static const std::map<std::string_view, int> mapView{
#include "elements.h"
};


static const std::unordered_map<std::string_view, int> unorderedMapView{
#include "elements.h"
};


static const boost::container::flat_map<std::string_view, int> flatMapView{
#include "elements.h"
};


static const std::vector<std::string> searchOrder{
#include "searchorder.h"
};



static void benchMap(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          map.find(a);
      }
  }
}
BENCHMARK(benchMap);



static void benchMapView(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          mapView.find(a);
      }
  }
}
BENCHMARK(benchMapView);


static void benchUnorderedMap(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          unorderedMap.find(a);
      }
  }
}
BENCHMARK(benchUnorderedMap);



static void benchUnorderedMapView(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          unorderedMapView.find(a);
      }
  }
}
BENCHMARK(benchUnorderedMapView);


static void benchFlatMap(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          flatMap.find(a);
      }
  }
}
BENCHMARK(benchFlatMap);


static void benchFlatMapView(benchmark::State& state) {
  for (auto _ : state) {
      for(const auto& a : searchOrder){
          flatMapView.find(a);
      }
  }
}
BENCHMARK(benchFlatMapView);



BENCHMARK_MAIN();
