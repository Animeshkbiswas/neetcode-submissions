class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n=points.length;
        //int[] vis=new int[n];
        HashMap<List<Integer>,Integer> map= new HashMap<>();
        for(int[]point : points){
            map.put(Arrays.asList(point[0],point[1]),0);
        }

        PriorityQueue<List<Integer>> pq = new PriorityQueue<>(
            (a,b)-> a.get(0)-b.get(0)        
            );
        pq.add(new ArrayList<>(Arrays.asList(0,points[0][0],points[0][1])));
        int count=0, sum=0;
        while(!pq.isEmpty()){
            List<Integer> curr= pq.remove();
            
            if (map.get(Arrays.asList(curr.get(1), curr.get(2))) == 1)
    continue;
            map.put(Arrays.asList(curr.get(1),curr.get(2)),1);
            count++;
            sum+=curr.get(0);
            for(int[] point : points){
                List<Integer> p=Arrays.asList(point[0],point[1]);
                if(map.get(p)==1)continue;
                int wt=Math.abs(p.get(0)-curr.get(1))+Math.abs(p.get(1)-curr.get(2));
                pq.add(Arrays.asList(wt,p.get(0),p.get(1)));
            }
            if(count==n)break;
        }
        return sum;
    }
}
