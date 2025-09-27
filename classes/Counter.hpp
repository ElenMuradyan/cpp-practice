class Counter {
    private: 
        int id;
        static int totalObj;
    public: 
        Counter() {
            totalObj++;
            id = totalObj;
        }

        int getId() const {
            return id;
        }

        static int getTotalObjs() {
            return totalObj;
        }
};